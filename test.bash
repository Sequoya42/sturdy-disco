


if [[ $# < 3 ]] ; then
    echo -e "${GRN}[3 args needed]\n"
    echo "Supply champion [.cor]"
   echo -e " and cycle to start with and how many cycle to increment by"
   echo -e "Example: bash test.bash bee_gees.cor 1000 50"
    exit 1
fi


ZAZ="/nfs/2014/r/rbaum/corewar_ressources/corewar" 

ME="/nfs/2014/r/rbaum/vm_corewar/corewar"

i=$2
LOC="/nfs/2014/r/rbaum/diff_vm"
mkdir -p $LOC

NZ=$LOC"/zaz"
NM=$LOC"/seq"

while [ i != 30000 ]
do

	$ZAZ -d $i $1 > $NZ
	$ME -d $i $1 > 	$NM
	diff  $NZ $NM
 	if [ $? != 0 ]
	then 
		break
	fi
	 i=$(($i+$3))
	 echo $i
done
	echo $i
