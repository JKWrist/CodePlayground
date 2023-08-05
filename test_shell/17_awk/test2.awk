BEGIN{
    printf "%s\t%s\n","产品","库存";
    sum=0;
}
{
    printf "%s\t%s\n",$1,$2;
    sum+=$2;
}
END{
    printf "库存总量:%d\n",sum
}
