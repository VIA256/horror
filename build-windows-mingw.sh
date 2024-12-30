CC="i686-w64-mingw32-gcc"
CFLAGS="-Wall -Wextra -Wpedantic -std=c99"
LDFLAGS="-lglfw3dll -lopengl32 -lm -lgdi32"
BDIR="build/windows"
SDIR="src"

ls $BDIR > /dev/null 2>&1 || mkdir -p $BDIR &&
	$CC $SDIR/game.c $CFLAGS -c -o $BDIR/game.o &&
	$CC $BDIR/*.o $SDIR/main.c $CFLAGS $LDFLAGS -o $BDIR/open-world &&
	rm $BDIR/*.o
