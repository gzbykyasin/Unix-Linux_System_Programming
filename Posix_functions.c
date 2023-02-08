// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int getopt(int argc, char * const argv[],const char *optstring);

extern char *optarg;
extern int optind, opterr, optopt;

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <getopt.h>

int getopt_long(int argc, char * const argv[],const char *optstring,const struct option *longopts, int *longindex);
int getopt_long_only(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <locale.h>
char* setlocale( int category, const char* locale );

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h> 

void perror(const char *str);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


#include <unistd.h>

char *getcwd(char *buf, size_t size);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int chdir(const char *path);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

task_struct (files) ---> files_struct (fdt) ---> fdtable (fd) --->  file * türünden bir dizi ---> file

proses kontrol block ---> betimleyici tablosu --> dosya nesneleri (Kısaca) 

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int open(const char *path, int flags, ...);


    O_RDONLY
    O_WRONLY
    O_RDWR
    
    S_IRUSR
    S_IWUSR
    S_IXUSR
    S_IRGRP
    S_IWGRP
    S_IXGRP
    S_IROTH
    S_IWOTH
    S_IXOTH
    
    S_IRWXU
    S_IRWXG
    S_IRWXO

    #define S_IRWXU (S_IRUSR|S_IWUSR|S_IXUSR)
    #define S_IRWXG (S_IRGRP|S_IWGRP|S_IXGRP)
    #define S_IRWXO (S_IROTH|S_IWOTH|S_IXOTH)
    
    S_IRWXU             0700        
    S_IRUSR             0400 
    S_IWUSR             0200 
    S_IXUSR             0100 
    S_IRWXG             070 
    S_IRGRP             040 
    S_IWGRP             020 
    S_IXGRP             010 
    S_IRWXO             07 
    S_IROTH             04 
    S_IWOTH             02 
    S_IXOTH             01 
    S_ISUID             04000 
    S_ISGID             02000 
    S_ISVTX             01000
    
    S_IRUSR        100 000 000
    S_IWUSR        010 000 000
    S_IXUSR        001 000 000

    S_IRGRP        000 100 000
    S_IWGRP        000 010 000
    S_IXGRP        001 001 000

    S_IROTH        000 000 100
    S_IWOTH        000 010 010
    S_IXOTH        001 001 001
    
    
    Standart C fopen                    POSIX
    "w"                                 O_WRONLY|O_CREAT|O_TRUNC
    "w+"                                O_RDWR|O_CREAT|O_TRUNC
    "r"                                 O_RDONLY
    "r+"                                O_RDWR
    "a"                                 O_WRONLY|O_CREAT|O_APPEND
    "a+"                                O_RDWR|O_CREAT|O_APPEND
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int creat(const char *path, mode_t mode);

int creat(const char *path, mode_t mode)
{
	return open(path, O_WRONLY|O_CREAT|O_TRUNC, mode);
}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

ssize_t read(int fd, void *buf, size_t nbyte);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t nbyte);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);

SEEK_SET
SEEK_CUR
SEEK_END

ör : lseek(fd, 0, SEEK_END);
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

mode_t umask(mode_t cmask);

   mode_t mode;

   mode = umask(0);
   umask(mode);
   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);

struct stat {
        dev_t     st_dev;         /* ID of device containing file */
        ino_t     st_ino;         /* Inode number */
        mode_t    st_mode;        /* File type and mode */
        nlink_t   st_nlink;       /* Number of hard links */
        uid_t     st_uid;         /* User ID of owner */
        gid_t     st_gid;         /* Group ID of owner */
        dev_t     st_rdev;        /* Device ID (if special file) */
        off_t     st_size;        /* Total size, in bytes */
        blksize_t st_blksize;     /* Block size for filesystem I/O */
        blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */

        /* Since Linux 2.6, the kernel supports nanosecond precision for the following timestamp fields.
           For the details before Linux 2.6, see NOTES. */

        struct timespec st_atim;  /* Time of last access */
        struct timespec st_mtim;  /* Time of last modification */
        struct timespec st_ctim;  /* Time of last status change */

    #define st_atime st_atim.tv_sec      /* Backward compatibility */
    #define st_mtime st_mtim.tv_sec
    #define st_ctime st_ctim.tv_sec
    };

   struct timespec {
        time_t  tv_sec;      
        long    tv_nsec;
    };


    S_ISBLK(m)      Blok aygıt sürücü dosyası mı? (ls -l'de 'b' dosya türü)
    S_ISCHR(m)      Karakter aygıt sürücü dosyası mı? (ls -l'de 'c' dosya türü)
    S_ISDIR(m)      Dizin dosyası mı? (ls -l'de 'd' dosya türü)
    S_ISFIFO(m)     Boru dosyası mı? (ls -l'de 'p' dosya türü)
    S_ISREG(m)      Sıradan bir disk dosyası mı? (ls -l'de '-' dosya türü)
    S_ISLNK(m)      Sembolik bağlantı dosyası mı? (ls -l'de 'l' dosya türü)
    S_ISSOCK(m)     Soket dosyası mı? (ls -l'de 's' dosya türü)
	
    S_IFBLK         Blok aygıt dosyası
    S_IFCHR         Karakter aygıt dosyası
    S_IFIFO         Boru dosyası
    S_IFREG         Sıradan disk dosyası
    S_IFDIR         Dizin dosyası
    S_IFLNK         Sembolik bağlantı dosyası
    S_IFSOCK        Soket dosyası
    
    S_IFMT
    
    (mode & S_IFMT) == S_IFXXX


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


#include <stdio.h>

int remove(const char *path);       

#include <unistd.h>

int unlink(const char *path);

remove'da unlink'te aynı işi yapıyor.
remove C fonksiyonudur. unlink ise POSIX fonksionudur
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	#ifdef _POSIX_CHOWN_RESTRICTED
	 	printf("chown restricted\n");
	#else
		printf("chown not restricted\n");
	#endif

	return 0;
}


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int chown(const char *path, uid_t owner, gid_t group);  
int fchown(int fd, uid_t owner, gid_t group);   

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int mkdir(const char *path, mode_t mode);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int rmdir(const char *path);  

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <pwd.h>

struct passwd *getpwnam(const char *name);
struct passwd *getpwuid(uid_t uid);


struct passwd {
        char   *pw_name;       /* username */
        char   *pw_passwd;     /* user password */
        uid_t   pw_uid;        /* user ID */
        gid_t   pw_gid;        /* group ID */
        char   *pw_gecos;      /* user information */
        char   *pw_dir;        /* home directory */
        char   *pw_shell;      /* shell program */
    };

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <pwd.h>

struct passwd *getpwent(void);
void setpwent(void);
void endpwent(void);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <grp.h>

struct group *getgrnam(const char *name);
struct group *getgrgid(gid_t gid);
struct group *getgrent(void);
void setgrent(void);
void endgrent(void);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int openat(int fd, const char *path, int oflag, ...);

Fonksiyonun prototipini open fonksiyonu ile karşılaştırınız:

int open(const char *path, int oflag, ...);


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

int fchmodat(int fd, const char *path, mode_t mode, int flag);
int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag);
int fstatat(int fd, const char *restrict path, struct stat *restrict buf, int flag);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


#include <dirent.h>

DIR *opendir(const char *dirname);

DIR *fdopendir(int fd);

struct dirent *readdir(DIR *dirp);

int closedir(DIR *dirp);


struct dirent {
        ino_t          d_ino;       /* Inode number */
        off_t          d_off;       /* Not an offset; see below */
        unsigned short d_reclen;    /* Length of this record */
        unsigned char  d_type;      /* Type of file; not supported
                                        by all filesystem types */
        char           d_name[256]; /* Null-terminated filename */
};

    DT_BLK      block device
    DT_CHR      character device
    DT_DIR      directory
    DT_FIFO     named pipe (FIFO)
    DT_LNK      symbolic link
    DT_REG      regular file.
    DT_SOCK     UNIX domain socket.
    DT_UNKNOWN  Bilinmeyen bir tür

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <dirent.h>

int dirfd(DIR *dirp);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int fstatat(int fd, const char *restrict path, struct stat *restrict buf, int flag);

Fonskiyonun fd parametresinin yanı sıra aynı zamanda bir flag parametresinin olduğuna dikkat ediniz. Bu parametre stat semantiğinin mi yoksa 
lstat semantiğinin mi uygulanacağını belirtmektedir. Eğer bu parametreye 0 geçilirse bu durumda stat semnatiği uygulanır Eğer bu parametreye 
AT_SYMLINK_NOFOLLOW değeri geçilirse bu durumda lstat semantiği uygulanmaktadır. AT_SYMLINK_NOFOLLOW sembolik sabiti <sys/stat.h> içerisinde değil
<fcntl.h> içerisinde bildirilmiştir. İşte biz yukarıdaki örnekte önce dizin'in betimleycisini dirfd fonksiyonu ile alıp bunu fstatat 
fonksiyonunda kullanırsak yol ifadesini düzenlememize gerek kalmaz. Aşağıdaki örnekte bu çözüm verilmiştir.

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <dirent.h>

long telldir(DIR *dirp);
void seekdir(DIR *dirp, long loc);
void rewinddir(DIR *dirp);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <dirent.h>

int alphasort(const struct dirent **d1, const struct dirent **d2);
int scandir(const char *dir, struct dirent ***namelist, int (*sel)(const struct dirent *),
	int (*compar)(const struct dirent **, const struct dirent **));  
	
int cmp(const struct **direnet1, const struct **dirent2); -> biz yazdık bunu

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#define _XOPEN_SOURCE 500

#include <ftw.h>

int nftw(const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int fd_limit, int flags);


	FTW_CHDIR: Eğer bu bayrak belirtilirse fonksiyon her dizine geçtiğinde prosesin çalışma dizinini de o dizin olarak değiştirmektedir. 

	FTW_DEPTH: Normalde dolaşım "pre-order" biçimde yapılmaktadır. Bu bayrak girilirse "post-order" dolaşım yapılır. Bayrağın ismi 
	yanlış 	verilmiştir. "pre-order" dolaşım demek bir dizin ile karşılaşıldığında önce dizin girişinin ele alnıması sonra özyineleme
	yapılması demektir. "post-order" dolaşım ise önce özyineleme yapılıp sonra dizin girişinin ele alınması demektir.
	Default durum "pre-order" dolaşım biçimindedir. 

	FTW_MOUNT: Bu bayrak belirtilirse özyineleme yapılırken bir "mount point" ile karşılaşılırsa o dosya sistemine girilmez. Default durumda 
	özyineleme sırasında bir "mount point" ile kaşılaşılırsa özyineleme o dosya sisteminin içime girilerek devam ettirilmektedir. 

	FTW_PHYS:  Default durumda nftw fonksiyonu bir sembolik link dosyası ile karşılaştığında linki izler ve link'in hedefine
	yönelik hareket eder. Daha önce bir böyle bir durumun sonsuz döngüye yol açabileceğinden bahsetmiştik. Bu nedenle biz özyinelemede 
	stat fonksiyonu yerine lstat fonksiyonunu kullanmıştık. İşte bu bayrak belirtilirse artık nftw fonksiyonu sembolik link dosyası
	ile karşılaştığında link'i izlemez, sembolik link dosyasının kendisi hakkında bilgi verir. 





int callback(const char *path, const struct stat *finfo, int flag, struct FTW *ftw);  -> biz yazdık

	struct FTW {
		int base;
		int level;
	};

	FTW_D: Bulunan giriş bir dizin girişidir.

	FTW_DNR: Bulunan giriş bir dizin girişidir. Ancak bu dizin'in içi okunamamaktadır. Dolayısıyla bu dizin özyinelemede dolaşılamayacaktır.

	FTW_DP: Post-order dolaşımda bir dizinle karşılaşıldığında bayrak FTW_D yerine FTW_DP olarak set edilmektedir. 

	FTW_F: Bulunan dizin girişi sıradan bir dıosyadır (regular file).

	FTW_NS: Bulunan dizin girişi için stat ya da lstat fonksiyonu başarısız olmuştur. Dolayısıyla fonksiyona geçirilen stat yapısı da
	anlamlı değildir. 

	FTW_SL: Bulunan giriş bir sembolik bağlantı dosyasına ilişkindir. Sembolik bağlantı dosyasının hedefi mevcuttur. 

	FTW_SLN: Bulunan giriş bir sembolik bağlantı dosyasına ilişkindir. Sembolik bağlantı dosyasının hedefi mevcut değildir ("danging klink" durumu). 

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int link(const char *oldpath, const char *newpath);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int linkat(int fd1, const char *path1, int fd2, const char *path2, int flag);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int symlink(const char *path1, const char *path2);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int symlinkat(const char *path1, int fd, const char *path2);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

ssize_t readlink(const char *path, char *buf, size_t bufsize);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int access(const char *path, int amode) 

	Fonksiyonun birinci parametresi erişim testinin yapılacağı dosyanın yol ifadesini belirtmektedir. İkinci parametresi test edilecek 
	erişimi belirtir. Bu parametre aşağıdaki sembolik sabitlerin bir düzeyinde OR'lanmasıyla oluşturulabilir:

	R_OK: Okuma yapılabilir mi?
	W_OK: Yazma yapılabilir mi?
	X_OK: Çalıştırılabilir mi?
	F_OK: Dosya var mı?

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <unistd.h>

int euidaccess(const char *pathname, int mode);
int eaccess(const char *pathname, int mode);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int faccessat(int fd, const char *path, int amode, int flag);

    Fonksiyonun birinci paraetresi ikinci parametresiyle belirtilen yol ifadesinin göreli olması durumunda aramanın yapılacağı 
    dizini belirtmektedir. Son parametre 0 geçilebilir ya da AT_EACCESS geçilebilir. Bu AT_EACCESS değeri test işleminin etkin kulalnı ve grup 
    id'lerine bakılarak yapılacağı anlamına gelmektedir. (Tabii ikinci parametre ile belirtilen yol ifadesi mutlak olduğunda birinci parametrede 
    belirtilen dizine ilişkin betimleyici yine dikkate alınmaz. Ancak üçüncü parametreyle belirtilen bayrak dikkate alınır)

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int dup(int fildes);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int dup2(int fildes, int fildes2);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

IO yönlendirmesi kabuk üzerinden de yapılabilmektedir. Kabukta ">" sembolü 1 numaralı betimleyicinin yönlendirileceği anlamına gelmektedir.
						   
Kabuk üzerinde "<" sembolü de 0 numaralı betimleyiciyi yönlendirmektedr.						   
						   
Aslında kabukta genel olarak yönlendirme için "n>" ve "n<" sembolleri de kullanılabilmektedir. Buradaki n betimleyicinin 
numarasını belirtir. Bu sayede biz herhangi bir betimleyiciyi okuma ve yazma amaçlı bir dosyaya yönlendirebiliriz.
ÖR: ./sample 2> test.txt

Tabii hem stdout dosyasını hem de stdin dosyasını kabuk üzerinden birlikte de yönlendirebiliriz. 
ÖR: ./sample > out.txt < in.txt
							   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------						   

<unistd.h> dosyasında okunabilirliği artırmak için şu sembolik sabitler bildirilmiştir:

#define STDIN_FILENO        0
#define STDOUT_FILENO       1
#define STDERR_FILENO       2

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

 IO yönlendirmesi kabuk üzerinden de yapılabilmektedir. Kabukta ">" sembolü 1 numaralı betimleyicinin yönlendirileceği anlamına gelmektedir. Örneğin:

./sample > test.txt

Bu durumda kabuk önce ">" sembolünün sağındaki dosyayı O_WRONLY|O_TRUNC modunda açar. Sonra ./sample programını çalıştırarak bu 
prosesin 1 numaralı betimleyicisini dup2 fonksiyonu ile bu dosyaya yönlendirir. Böylece ./sample sample programının ekrana yazdığını
zannettiği ieşyle bu dosyaya yazılmış olacaktır. 

ls gibi, cat gibi kabuk komutlarının da aslında birer program olduğuna bunların da 1 numaralı betimleyiciyi kullanarak yazdırma 
yaptığına dikkat ediniz. Örneğimn biz kabuk üzerinde şu komutu uygulayabiliriz:

ls -l > test.txt

Eğer kabulta ">" yerine ">>" sembolü kullanılırsa bu durumda ">>" sembolünün sağındaki dosya O_CREAT|O_WRONLY|O_APPEND modunda 
açılmaktadır. Yani dosya varsa bu durumda olan dosyanın sonuna ekleme yapılacaktır. Örneğin:

ls -l >> test.txt						   

Kabuk üzerinde "<" sembolü de 0 numaralı betimleyiciyi yönlendirmektedr. Örneğin:

./sample < test.txt

Burada kabuk "test.txt" dosyasını O_RDONLY modda açar. Sonra ./sample programını çalıştırır. Prosesin 0 numaralı betimleyicisini
"test.txt" dosyasına dup2 fonksiyonuyla yönlendirir. Böylece rpogram sanki klavyeden okuduğunu sanırken aslında dosyadan okuma
yapacaktır.


Aslında kabukta genel olarak yönlendirme için "n>" ve "n<" sembolleri de kullanılabilmektedir. Buradaki n betimleyicinin 
numarasını belirtir. Bu sayede biz herhangi bir betimleyiciyi okuma ve yazma amaçlı bir dosyaya yönlendirebiliriz. Örneğin:

./sample 2> test.txt

Burada "test.txt" dosyası açılıp ./sample programının "stderr" olarak isimlendirilen 2 numaralı betimleyicisi bu dosyaya 
yönlendirilecektir. 

Kabuk programları ">", "<", "n>" "n<" gibi yönlendirmeleri nasıl yapmaktadır? Bu konu ileride ele alınacaktır. Kabuk önce bir kez
fork işlemi yapar. Sonra yönlendirme işlemini gerçekleştirir. Sonra da exec işlemi yapmaktadır.
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

Komut satırındaki diğer önemli bir işlem de "boru (pipe)" işlemidir. Boru işlemi "|" ile temsil edilmektedir. Kabul üzerinden
aşağıdaki gibi bir komut uygulamış olalım:

a | b

Burada kabuk bu yazıyı "|" karakterindne parse eder. "|" karakterinin solundaki ve sağındakileri birer program olarak ele alır. 
Her iki programı da çalışırır. Yani burada "a" programı da "b" programı da çalıştırılacaktır. "a" programının "stdout" dosyasına
yazdıklarını "b" programı "stdin" dosyasından okuyacaktır. Başka bir deyişle "a" programının 1 numaralı betimeyiciyle yaptuığı write 
işlemlerini "b" programı 0 numaralı betimleyici ile read fonksiyonunu kullanarak okuyabilecektir. Kabuk boru işlemlerini
"prosesler arası haberleşme yöntemlerindne biri olan boru haberleşmesi ile" gerçekleştirmektedir. Zaten ilerleyen bölümlerde 
bu konu ele alınacaktır. 

Tabii boru işlemi yapılırken programların komut satırı arümanları da verilebilir. Örneğin:

a b c | d e f

Burada aslında çalıştırılacak programlar "a" ve "d" programlarıdır. Diğerleri bunların komut satırı argümanlarıdır. 

Aşağıdaki örnekte "a" programı ekrana (stdout dosyasına) 0'dan 10'a kadar sayıları yazdırmaktadır. "b" programı ise
döngü içerisinde klavyeden (stdin dosyasından) değer okuyup ekrana yazdırmaktadır. Bu iki programı aşağıdkai gibi çalıştıralım:

./a | ./b
						   
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>

int fileno(FILE *stream);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>

FILE *fdopen(int fd, const char *mode);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>

void setbuf(FILE *stream, char *buf);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>

int setvbuf(FILE *stream, char *buf, int mode, size_t size);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

void clear_stdin(void)
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
	    ;
}

						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>

int getchar(void);
char *gets(char *s);
char *gets_s(char *s, rsize_t n);
char *fgets(char *s, size_t n, FILE *f);
int scanf(const char *format, ...);
int getc(FILE *stream);
int ungetc(int c, FILE *stream);

						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

pid_t getpid(void);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


#include <unistd.h>

pid_t getppid(void);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

pid_t fork(void);    				   

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

void _exit(int status);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdlib.h>

void exit(int status);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
#include <sys/wait.h>

pid_t wait(int *wstatus);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *stat_loc, int options);

Fonksiyonun birinci parametresi beklenecek alt prosesin proses id değerini belirtir. Bu sayede programcı belli bir alt prosesi bekleyebilmektedir. 
Bu birinci parametre aslına birkaç biçimde geçilebilmektedir. Eğer bu parametre negatif bir proses id değeri olarak geçilirse 
bu durumda fonksiyon proses grup id'si bu değerin pozitifi olan herhangi bir alt prosesi beklemektedir. Eğer bu parametre -1 
olarak geçilirse bu durumda fonksiyon tamamen wait fonksiyonundaki gibi davranmaktadır. Yani herhangi bir alt prosesi beklemektedir.
Eğer bu parametre 0 olarak geçilirse fonksiyon proses grup id'si waitpid fonksiyonunu çağıran prosesin id'si ile yanı olan 
herhangi bir alt prosesi beklemektedir. Tabii normal olarak bu parametreye programcı pozitif olan bir proses id geçer. Bu durumda
fonksiyon  o alt prosesi bekleyecektir. (Tabii bu parametreye geçilen proses id o prosesin bir alt prosesi değilse fonksiyon yine
başarısız olmaktadır.) Fonksiyonun ikinci parametresi exit bilgisinin yerleştirileceği int türden nesnesnin adresini alır. Üçüncü 
parametre bazı özel değerlerin bit düzeyinde OR'lanmasıyla oluşturulabilmektedir:

WNOHANG: Bu durumda waitpid eğer alt proses henüz sonlanmamışsa bekleme yapmaz, başarısızlıkla sonuçlanır. 
WCONTINUED, WUNTRACED: Bu bayrakların açıklaması burada yapılmayacaktır. 

Tabii bu üçüncü parametre genellikle 0 geçilmektedir. 0 geçilmesi bu bayraklardan hiçbirinin kullanılmayacağı anlamına gelmektedir. 
O halde aslında wait(&status) çağrısı ile waitpid(-1, &status, 0) eşdeğerdir. 

waitpid fonksiyonunda da ikinci parametre NULL adres geçilebilir. Bu durumda proses beklenir ama exit bilgileri elde edilmez. 

waitpid fonksiyonu da başarı durumunda beklenen proses id değeri ile başarısızlık durumunda -1 değeriyle geri dönmektedir. 

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
#include <stdlib.h>

extern char **environ;
						   
char *getenv(const char *name);
					
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
#include <stdlib.h>

int setenv(const char *name, const char *value, int overwrite);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdlib.h>

int putenv(char *str);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdlib.h>

int unsetenv(const char *name);
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

execl
execle
execlp
execv
execve (Linux'ta sistem fonksiyonu olarak yazılmıştır)
execvp
fexecve (Linux'ta execveat sistem fonksiyonu)						   


#include <unistd.h>

int execl(const char *path, const char *arg0, ... /*, (char *)0 */);   
int execv(const char *path, char * const *argv);	 
int execlp(const char *file, const char *arg0, ... /*, (char *)0 */);
int execvp(const char *file, char *const argv[]);
int execle(const char *path, const char *arg0, ... /*, (char *)0, char *const envp[]*/);
int execve(const char *path, char *const argv[], char *const envp[]);

pid_t vfork(void);
	 
int fexecve(int fd, char *const argv[], char *const envp[]);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
						   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
