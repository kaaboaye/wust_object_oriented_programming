#ifndef RUNTIME_H
#define RUNTIME_H

#include "compiler.h"

namespace runtime {
void run(compiler::bytecode_t bytecode);
}

#endif