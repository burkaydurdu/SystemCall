# Sistem Çağrıları

Sistem çağrıları . ```Bir komutun, çekirdekten(kernel) hizmet taleb etmesi```
anlamına gelir. Genelde giriş/çıkıs işlemlerinde bu talebler çekirdeğe iletilir.

## Open

 #### open( path, flags, mode );
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
  ###### Mode :
   Dosya erişim izinleri atama *```777```* vs *```0777```* vs *```0x777```* gibi

   Open geriye bir integer değer döndürür bu deger **file description (fd)** dir. Dosyanın tanımlayan fd dir.
   bu değerler 0-255 arasında değişen değerlerdir. ```0 (stdin)``` ```1(stdout)``` ```2(stderr)```
   bunlardan sonra gelicek en kucuk değerler sırasıyla atanır. Bash shell üzerinden değeri kendimizde verebiliriz.
   *exec 5>file* 5.fd yı file adında dosyaya yazmak için eriştik.
