ME=`whoami`

IPCS_S2=`ipcs -s | egrep "0x[0-9a-f]+" | grep $ME | cut -f2 -d" "`
IPCS_S3=`ipcs -s | egrep "0x[0-9a-f]+" | grep $ME | cut -f3 -d" "`
IPCS_M2=`ipcs -m | egrep "[0-9]" | grep $ME | cut -f2 -d" "`
IPCS_M3=`ipcs -m | egrep "[0-9]" | grep $ME | cut -f3 -d" "`

for id in $IPCS_M2; do
	ipcrm -m $id;
	echo "$id has been remove"
done

for id in $IPCS_S2; do
	ipcrm -s $id;
done

for id in $IPCS_M3; do
	ipcrm -m $id;
	echo "$id has been remove"
done

for id in $IPCS_S3; do
	ipcrm -s $id;
done
