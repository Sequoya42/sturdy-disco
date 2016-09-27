
# if [[ $# != 1 ]] ; then
#    echo -e " directory to be created for testing ${NC}"
#     exit 1
# fi

if [[ $# != 2 ]];
	then
		echo -e "Please provide two dir (src and dest)\n"
		exit 1
fi
mkdir -p $2
echo $1
test=`find "$1/" -type f -exec echo '{}' \;`
for i in $test; do
EXT=$(echo "$i" | rev | cut -d . -f1 | rev)
	if [ "$EXT" = "s" ];
	then
	cp $i $2
fi
done