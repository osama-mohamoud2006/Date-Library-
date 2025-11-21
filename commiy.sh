#!/bin/bash

# ================================
# 🚀 Settings
# ================================
project_dir="E:/projects/c++ course/10-OOP Concepts/Project 3"
remote_repo="https://github.com/osama-mohamoud2006/Date-Libra.git"
gitignore_file=".gitignore"

# ================================
# 📂 Move to project directory
# ================================
cd "$project_dir" || { echo "❌ Project directory not found"; exit 1; }

# ================================
# 🛡️ Create .gitignore if missing
# ================================
if [ ! -f "$gitignore_file" ]; then
    echo ".vs/" > "$gitignore_file"
    echo "🧷 Created .gitignore"
else
    grep -qxF ".vs/" "$gitignore_file" || echo ".vs/" >> "$gitignore_file"
fi

# ================================
# 🔧 Initialize Git repo
# ================================
if [ ! -d ".git" ]; then
    echo "🚀 Initializing Git repository…"
    git init --quiet
    git branch -M main
fi

# ================================
# ♻️ Remove .vs if tracked
# ================================
if git ls-files --error-unmatch ".vs/" > /dev/null 2>&1; then
    git rm -r --cached .vs/ --quiet
fi

# ================================
# 🔗 Connect new remote repo
# ================================
git remote remove origin 2>/dev/null
git remote add origin "$remote_repo"
echo "🔗 Connected to remote repo: $remote_repo"

# ================================
# 🧠 Commit changes
# ================================
git add -u
git add .

commit_msg="Initial commit: $(date '+%Y-%m-%d %H:%M:%S')"
git commit -m "$commit_msg" --quiet || echo "⚠️ Nothing to commit."

# ================================
# 📤 Push to GitHub
# ================================
echo "📤 Pushing to GitHub…"
git push -u origin main --quiet || echo "🚫 Push failed (check repo permissions)."

echo "✅ Done! Project successfully pushed."
