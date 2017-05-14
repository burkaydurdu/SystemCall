# Sistem Çağrıları

Sistem çağrıları . ```Bir komutun, çekirdekten(kernel) hizmet taleb etmesi```
anlamına gelir. Genelde giriş/çıkıs işlemlerinde bu talebler çekirdeğe iletilir.

#### Sistem çağrıları(Sınıf)
```
 File managment
 Process managment
 Communication
 Error and Signal hadling
```

>prog -> libC.so kullanıp write() -> kernel (buffer'a yazar)</br>
>prog -> write() direk sistem cağrısıyla hedefe yazar.

Kütüphane yardımıyla yapılan I/O işlemleri **stdio** ile olur ve yazimlarda öncelik buffer yazılır.
Eğer kütüphane yardımı olmadan direk sistem çağrısıyla erişiyorsanız *(unbuffered)I/O* bufferlanmadan yazilir.
Bufferda bekletilen veriler 4 yolla hedefe ulaşır.
> 1- Buffer doldugunda hedefe yazilir.
> 2- Gönderilen veride *new line* karakteri varsa hedefe yazılır.</br>
> 3- Buffer yazan sürecin icrasi sona erdiğinde hedefe yazilir.</br>
> 4- **flush()** komutu kullanarak hedefe yazılır.</br>

``error`` yazilari bufferlanmaz direk yazilir.
```

  char buff[] = "---";
  char buff2[] = "***";
  char buff3[] = "!!!";

  fprintf(stdout,buff2);
  fprintf(stderr,buff3);
  int a = write(2,buff,4);

  out: !!!---***  
```

** NOT **
>Bütün sistem çağrilari geri birşey döndürür fakat **exit()** geriye birşey döndürmez.

## Open

 #### int open( path, flags, mode );
 Biçiminde dosya erişimi açmaya yarayan bir sistem çağrısıdır.


  > **path** : ile dosya yolunu veriyoruz.</br>
  > **flags** : ile erişilen dosyaya ne yapmak için erişildiğini belirtiyor. </br>
  > **mode** : ile eğer dosya ilk defa oluşturuluyorsa dosya erişim izinlerini veriyoruz.


  ###### Flags :
  ```
  O_RDONLY : Sadece Okuma
  0_WRONLY : Sadece Yazma
  O_RDWR : Hem Yazma Hem okuma
  O_APPEND : Son satirdan itibaren Yazma
  O_CREAT : Dosya Oluşturma
  O_TRUNC : Dosta mevcut ise içeriği sil
  ```
  Bash kullanilan **>** fd yonlendirme  open komutu ile
  **O_WRONLY|O_CREAT|O_TRUNC** setlenerek yapılır.
  **>>** fd yönlendirmesi.
  **O_WRONLY|O_CREAT|O_APPEND** setlenerek yapılır.

  ###### Mode :
   Dosya erişim izinleri atama *```777```* vs *```0777```* vs *```0x777```* gibi

   Open geriye bir integer değer döndürür bu deger **file description (fd)** dir. Dosyanın tanımlayan fd dir.
   bu değerler 0-255 arasında değişen değerlerdir. ```0 (stdin)``` ```1(stdout)``` ```2(stderr)```
   bunlardan sonra gelicek en kucuk değerler sırasıyla atanır. Bash shell üzerinden değeri kendimizde verebiliriz.
   *exec 5>file* 5.fd yı file adında dosyaya yazmak için eriştik.

   ## READ

   #### int read(fd, buff, leng);

   geriye döndürdüğü değer ne kadar okuma yaptığı bilgisi yer alır.

   ## WRITE
   #### int write(fd, buff, leng);

   geriye döndürdüğü değer ne kadar yazdığı bilgisi yer alır.

   ## CLOSE

   #### int close(fd)

   fd serbest bırakır. Geçerli bir fd değilse -1 döndürür.

   ## LSEEK

   #### int lseek(fd, offset, whence);

   file pointer ın yerini değiştirmeye yarıyor.
   **file pointer**: kaynak üzerinde okuma yazma yapacağı konum.
   Geriye döndürdüğü değer yeni offset yani konumu.

  whence
   ```
   SET : Herhangi bir referans almaz offset atanan değer kadar ilerletir.
   CUR : File pointer bulunduğu konumdan itibaren offset kadar ilerletir.
   END : Dosya sonundan itibaren - offset vererek sondan konumlandırma yaparız.

   ```
   lseek -1 dönerse kaynak yok yani file pointer yok.

   ## CREAT

   #### int creat(path, mode)

   **open(path,O_WRONLY|0_CREAT|O_TRUNC)** la eşdeğerdir.
