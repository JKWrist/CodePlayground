A=123
[ -n "$A" ] && [ "$A" -lt 100 ] || echo '111 too big!'

unset A
[ -n "$A" ] && ([ "$A" -lt 100] || echo '222 too big!')

[ -n "$A" ] && {[ "$A" -lt 100 ] || echo '333 too big!'}