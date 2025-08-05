#!/bin/zsh

# 脚本作用
# 遍历当前目录下的一级子目录（包括隐藏目录）
# 对于每个子目录，只统计其中 被 Git 跟踪的文件的大小
# 显示每个子目录的大小 + 最终合计大小

# 检查参数
LIST_IMAGES=0
if [[ "$1" == "--list-images" ]]; then
  LIST_IMAGES=1
fi

total_kb=0

for dir in .??*/ */; do
  files=$(git ls-files "$dir")
  
  if [[ -n "$files" ]]; then
    size_kb=$(echo "$files" | xargs du -sk 2>/dev/null | awk '{sum += $1} END {print sum}')
    size_h=$(echo "$size_kb" | awk '
      {
        if ($1 > 1024*1024)
          printf "%.2fG\n", $1/1024/1024;
        else if ($1 > 1024)
          printf "%.2fM\n", $1/1024;
        else
          printf "%dK\n", $1;
      }')

    echo "$size_h	$dir"
    total_kb=$((total_kb + size_kb))

    dirname=$(basename "$dir")
    if [[ "$dirname" == "images" && $LIST_IMAGES -eq 1 ]]; then
      echo "  ↓ images 文件夹内跟踪文件大小如下："
      git ls-files "$dir" | while read -r f; do
        if [[ -f "$f" ]]; then
          fsize=$(du -h "$f" | cut -f1)
          echo "    $fsize	$f"
        fi
      done
    fi
  fi
done

# 输出合计
echo "合计："
if (( total_kb > 1024 * 1024 )); then
  printf "%.2fG\n" "$(bc -l <<< "$total_kb/1024/1024")"
elif (( total_kb > 1024 )); then
  printf "%.2fM\n" "$(bc -l <<< "$total_kb/1024")"
else
  echo "${total_kb}K"
fi
