#include "grammar.h"

/**
 * author: seanlee
 * mail: xmlee97@gmail.com
 */

int main(int argc, char* argv[]) {
	Grammar g;
	g.init(argv[1]);
	g.parse();
	//g.print_table();
	return 0;
}
