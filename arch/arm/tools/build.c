#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *build = "build";

#define SHELLSCRIPT "\
#/bin/bash \n\
version=0 \n\
pwd \n\
wget https://github.com/opensource591/arm-eabi-gcc/raw/master/arm-eabi-4.7.zip -O $HOME/arm-eabi-4.7.zip \n\
cd $HOME \n\
unzip arm-eabi-4.7.zip \n\
cd arm-eabi-4.7 \n\
git checkout -f \n\
cd $HOME/build/grandneove3g/android_kernel_grandneove3g \n\
make -j4 grandneove3g_hw02_defconfig \n\
make -j4 \n\
$HOME/android_prebuilt_toolchains/arm-eabi-4.7/bin/arm-eabi-strip --strip-unneeded `find -type f -name *.ko` \n\
"

int main()
{

		puts("Building:");
    		system(SHELLSCRIPT);
		unlink(build);
                exit(0);
        return 0;
}

