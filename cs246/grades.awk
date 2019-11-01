BEGIN {
    FS=":";
    g=/egrep -c $1/
}

NR==1{
    printf "%-25s %-10s %-10s %-9s %-0s\n", $1, $2, $3, $4, "Average"; 

    while (j++<21) printf "="; while (k++<4) printf " ==========";
    printf "\n"
}

{
    avg=($2+$3+$4)/3.0
}

NR>=2||NR<=g{
    printf "%-29s %-10d %-10d %-8d %-0.1f\n", $1, $2, $3, $4, avg;

    avg1+=$2;
    avg2+=$3;
    avg3+=$4;
    avg4+=avg
}

END {
    while (s++<21) printf "=";
    while (b++<4) printf " ==========";
    printf "\n";
    printf "%-29s %-10d %-10d %-8d %-0.1f\n","Average", avg1/(FNR-1),
	avg2/(FNR-1), avg3/(FNR-1), avg4/(FNR-1)

} 
     
     
