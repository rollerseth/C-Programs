{
    counts[$1]++;
    counting=0;
    for (k in counts) {

	counting+=counts[k]
       }
}

END {

    for (j in counts) {
	percent=counts[j]/counting
	num=(percent*100)/2
	
	
	printf "%0d%-12s %-1d", j,":", counts[j]
	for (i=0; i < int (num)+1; i++)
	    printf "*"
	printf "\n"
	
	
	
    }
  
}
    
