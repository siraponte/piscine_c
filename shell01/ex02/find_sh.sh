find . -type f -name "*.sh" | grep -o '[^/]*$' | sed 's/.sh$//g'
