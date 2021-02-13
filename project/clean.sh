################ clean my libasm project mess ################
##### HOW_TO_USE:
# with option 1 you can remove only object files
# with option 2 you can remove only executable files
# with no option delete everthing if existed

remove_binary_files ()
{
	i=0
	for FILE in *
	do
		file_type=$(file $FILE | grep "64-bit LSB shared object")
		if [ $? -eq 0 ]
		then
			rm -I $FILE
		fi
		i=$(($i+1))
	done
}

remove_object_files ()
{
	for FILE in *.o
	do
		if [ -e FILE ]
		then
			rm -I $FILE
		fi
	done
}

if [ $# -ne 1 ] # if there no arrguments
then
	remove_binary_files
	remove_object_files

	elif [ $1 -eq 1 ] # if you want to delete an object file
	then
		remove_object_files
	elif [ $1 -eq 2 ] # if you want to delete a binary file
	then
		remove_binary_files
fi