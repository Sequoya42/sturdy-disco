

ZAZ="/nfs/2014/r/rbaum/corewar_ressources/corewar" 

ME="/nfs/2014/r/rbaum/vm_corewar/corewar"

i=0
LOC="/nfs/2014/r/rbaum/diff_vm"
mkdir -p $LOC

NZ=$LOC"/zaz"
NM=$LOC"/seq"

while [ true ]
do

	$ZAZ -d $i $1 > $NZ
	$ME -d $i $1 > 	$NM
	diff $NZ $NM
	(( i++ ))
	if [ $? != 0 ]
	then 
		break
	fi
done
	echo $i
