const process = async () => {
  // 必须有 workspace
  if (!workspaceFolders || workspaceFolders.length === 0) {
    return [];
  }

  const root = workspaceFolders[0].path;
  const results = [];

  // 清洗函数：保证文件夹/文件名安全
  const safe = (s) =>
    String(s)
      .trim()
      .replace(/[\/\\:*?"<>|]/g, "_") // 禁止字符
      .replace(/\s+/g, "_")          // 空格换 _
      .slice(0, 120);

  for (const problem of problems) {
    try {
      const name = problem?.name ?? "Problem";
      const group = problem?.group ?? "OJ - Contest";

      // group 示例：
      // "Codeforces - Codeforces Round 644 (Div. 3)"
      const parts = String(group).split(" - ");
      const platform = parts[0] ? parts[0].trim() : "OJ";
      let contest = parts[1] ? parts[1].trim() : "Contest";

      /* ✅AtCoder 特判：只保留括号里的比赛名 */
      if (platform === "AtCoder") {
        const match = contest.match(/\(([^()]+)\)$/);
        if (match) {
          contest = match[1];
          // contest 变成 "AtCoder Beginner Contest 437"
        }
      }

      // 目录：OJ/平台/比赛/
      const dir =
        contest !== "Contest"
          ? path.join(root, "OJ", safe(platform), safe(contest))
          : path.join(root, "OJ", safe(platform));
      // 文件名：题目名.cpp
      let base = safe(name);

      // ✅Codeforces 特判：从 url 提取编号
      // if (platform === "Codeforces" && problem?.url) {
      //   const url = problem.url;

      //   const patterns = [
      //     /\/problemset\/problem\/(\d+)\/([A-Z0-9]+)/,
      //     /\/contest\/(\d+)\/problem\/([A-Z0-9]+)/,
      //     /\/gym\/(\d+)\/problem\/([A-Z0-9]+)/,
      //   ];

      //   for (const reg of patterns) {
      //     const m = url.match(reg);
      //     if (m) {
      //       base = `${m[1]}${m[2]}`; // 1360 + D
      //       break;
      //     }
      //   }
      // }

      // 防止出现 .cpp.cpp
      if (base.toLowerCase().endsWith(".cpp")) {
        base = base.slice(0, -4);
      }

      const filePath = path.join(dir, `${base}.cpp`);

      results.push(filePath);
    } catch (e) {
      logger?.error?.("Error generating file path", e?.message ?? e);
      results.push(null);
    }
  }

  return results;
};

// ✅关键：必须 return，否则就是 executed null
return await process();
