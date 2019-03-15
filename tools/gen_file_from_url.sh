url=$1
file=$(echo $url | awk -F'/' '{des=$NF;
    if (des) {
        des=$(NF-1);
    }
    printf("%s.cc\n", des);
}' | sed 's/-/_/g')
touch src/$file
