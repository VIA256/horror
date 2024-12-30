CC="cc"
CFLAGS="-Wall -Wextra -Wpedantic -std=c99"
LDFLAGS="-lglfw3 -lGL -lm"
BDIR="build/linux"
SDIR="src"

ls $BDIR > /dev/null 2>&1 || mkdir -p $BDIR &&
	$CC $SDIR/game.c $CFLAGS -c -o $BDIR/game.o &&
	$CC $BDIR/*.o $SDIR/main.c $CFLAGS $LDFLAGS -o $BDIR/open-world &&
	rm $BDIR/*.o
