html_file=tools/leetcode.html
if [[ -f $html_file ]]; then
    rm $html_file
fi
wget http://oj.leetcode.com/problems/ -O $html_file
file_list=$(grep -E 'a href="/problems.+</a>$' $html_file | awk -F'/' '{
    printf("%s.cc\n",$(NF-2))}' | sed 's/-/_/g')
for file in $file_list
do
  src_file=src/$file
  echo $src_file
  if [[ ! -f $src_file ]]; then
    touch $src_file
  fi
done
