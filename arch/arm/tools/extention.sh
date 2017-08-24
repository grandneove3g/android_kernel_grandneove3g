##to be added later in build script
mkdir system \n\
mkdir system/lib/ \n\
mkdir system/lib/modules \n\
rsync -r `find -type f -name '*.ko'` system/lib/modules \n\
cp arch/arm/boot/Image arch/arm/tools/zImage \n\
mv system arch/arm/tools/ \n\
cd arch/arm/tools \n\
gcc -o mkbootimg libmincrypt/*.c mkbootimg.c -Iinclude \n\
./mkbootimg --kernel zImage  --ramdisk boot.img-ramdisk.gz --ramdisk_offset 01300000 --tags_offset 00000100 --base 00200000 --pagesize 4096 -o boot.img \n\
zip -r tmp META-INF boot.img system  \n\
rm -rf system boot.img zImage mkbootimg \n\
mv -f tmp.zip ../../../kernel-$(date +%Y%m%d)-3.4.$version-UNOFFICIAL-grandneove3g.zip  \n\
