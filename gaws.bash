

if [[ $# < 3 ]] ; then
    echo -e "${GRN}[2 args needed]\n"
    echo "Supply cycle"
   echo -e " and champ [up to four]"
   echo -e "Example: gaws.bash  X [.cor]"
    exit 1
fi

ZAZ="/nfs/2014/r/rbaum/corewar_ressources/corewar" 

ME="/nfs/2014/r/rbaum/vm_corewar/corewar"

i=$2
LOC="/nfs/2014/r/rbaum/vm_corewar"
mkdir -p $LOC

NZ=$LOC"/zaz_fight"
NM=$LOC"/seq_fight"

$ZAZ  $2 $3 $4 $5  -v 23 > $NZ

$ME  $2 $3 $4 $5 > $NM

