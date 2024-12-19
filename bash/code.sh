read line
if [[ ${#line} -gt 2 && ${line:0:1} == \" && ${line: -1} == \" ]]; 
then
    echo "${line:1:-1}"
else
    echo CE
fi