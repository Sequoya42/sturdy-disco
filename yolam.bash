


if [[ $# < 3 ]] ; then
    echo -e "${GRN}[3+ args needed]\n"
   echo -e "Cycle to start with and how many cycle to increment by"
   echo -e "Example: bash 1000 50 test.bash bee_gees.cor [champ.cor]"
    echo "Supply champion [.cor]"
    exit 1
fi


ZAZ="/nfs/2014/r/rbaum/corewar_ressources/corewar" 

ME="/nfs/2014/r/rbaum/vm_corewar/corewar"

i=$1
LOC="/nfs/2014/r/rbaum/diff_vm"
mkdir -p $LOC

NZ=$LOC"/zaz"
NM=$LOC"/seq"

while [ i != 30000 ]
do

	$ZAZ -d $i $3 $4 $5 $6 > $NZ
	$ME -d $i $3 $4 $5 $6 >  $NM
	diff  $NZ $NM
 	if [ $? != 0 ]
	then 
		break
	fi
	 i=$(($i+$2))
	 echo $i
done
	echo $i
