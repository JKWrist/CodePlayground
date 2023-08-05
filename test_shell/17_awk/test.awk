$2 < 75 {
    printf "%s\t%s\n",$0,"REORDER";
    }
$2 >= 75 {
    printf "%s\n",$0;
    }
