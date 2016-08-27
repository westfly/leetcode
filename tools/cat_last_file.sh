deploy_code="src"
last_file_name=$(ls -rt $deploy_code/*cc | tail -n1)
if [[ $? -eq 0 ]]; then
    cat $last_file_name
fi
