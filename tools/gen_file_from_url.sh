url=$1
file=$(echo $url | awk -F'/' '{des=$NF;
    if (des == "") {
        des=$(NF-1);
    }
    printf("src/%s.cc\n", des);
}' | sed 's/-/_/g')
echo "$file"
if [[ ! -f $file ]];then
    cp tools/code.snappit $file
fi
touch $file
