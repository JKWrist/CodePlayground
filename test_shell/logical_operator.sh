A=123
[ -n "$A" ] && echo "111 A is not null"
unset A
[ -n "$A" ] && echo "222 A is not null"
[ -n "$A" ] || echo "333 A is null"