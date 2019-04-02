/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/errno/errno_str.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
const char *const	errno_str[134][2] = {
	[  0] = {"0", "0"},
	/* <asm-generic/errno-base.h> (1 - 34) */
	[  1] = {"EPERM",		"Operation not permitted (POSIX.1)."},
	[  2] = {"ENOENT",		"No such file or directory (POSIX.1)."},
	[  3] = {"ESRCH",		"No such process (POSIX.1)."},
	[  4] = {"EINTR",		"Interrupted function call (POSIX.1); see signal(7)."},
	[  5] = {"EIO",			"I/O error (POSIX.1)."},
	[  6] = {"ENXIO",		"No such device or address (POSIX.1)."},
	[  7] = {"E2BIG",		"Argument list too long (POSIX.1)."},
	[  8] = {"ENOEXEC",		"Exec format error (POSIX.1)."},
	[  9] = {"EBADF",		"Bad file descriptor (POSIX.1)."},

	[ 10] = {"ECHILD",		"No child processes (POSIX.1)."},
	[ 11] = {"EAGAIN",		"Resource temporarily unavailable (may be the same value as EWOULDBLOCK) (POSIX.1)."},
	[ 12] = {"ENOMEM",		"Out of memory (POSIX.1)."},
	[ 13] = {"EACCES",		"Permission denied (POSIX.1)."},
	[ 14] = {"EFAULT",		"Bad address (POSIX.1)."},
	[ 15] = {"ENOTBLK",		"Block device required"},
	[ 16] = {"EBUSY",		"Device or resource busy (POSIX.1)."},
	[ 17] = {"EEXIST",		"File exists (POSIX.1)."},
	[ 18] = {"EXDEV",		"Cross-device link (POSIX.1)."},
	[ 19] = {"ENODEV",		"No such device (POSIX.1)."},

	[ 20] = {"ENOTDIR",		"Not a directory (POSIX.1)."},
	[ 21] = {"EISDIR",		"Is a directory (POSIX.1)."},
	[ 22] = {"EINVAL",		"Invalid argument (POSIX.1)."},
	[ 23] = {"ENFILE",		"Too many open files in system (POSIX.1).  On Linux, this is probably a result of encountering the /proc/sys/fs/file-max limit (see proc(5))."},
	[ 24] = {"EMFILE",		"Too many open files (POSIX.1).  Commonly caused by exceeding the RLIMIT_NOFILE resource limit described in getrlimit(2)."},
	[ 25] = {"ENOTTY",		"Inappropriate I/O control operation (POSIX.1)."},
	[ 26] = {"ETXTBSY",		"Text file busy (POSIX.1)."},
	[ 27] = {"EFBIG",		"File too large (POSIX.1)."},
	[ 28] = {"ENOSPC",		"No space left on device (POSIX.1)."},
	[ 29] = {"ESPIPE",		"Illegal seek (POSIX.1)."},

	[ 30] = {"EROFS",		"Read-only file system (POSIX.1)."},
	[ 31] = {"EMLINK",		"Too many links (POSIX.1)."},
	[ 32] = {"EPIPE",		"Broken pipe (POSIX.1)."},
	[ 33] = {"EDOM",		"Math argument out of domain of func (POSIX.1, C99)."},
	[ 34] = {"ERANGE",		"Math result not representable (POSIX.1, C99)."},
	/* <asm-generic/errno.h> (35 - 133) */
	[ 35] = {"EDEADLK",		"Resource deadlock would occur (POSIX.1)."},
	[ 36] = {"ENAMETOOLONG",	"File name too long (POSIX.1)."},
	[ 37] = {"ENOLCK",		"No record locks available (POSIX.1)."},
	[ 38] = {"ENOSYS",		"Invalid system call number (POSIX.1)."},
	[ 39] = {"ENOTEMPTY",		"Directory not empty (POSIX.1)."},

	[ 40] = {"ELOOP",		"Too many symbolic links encountered (POSIX.1)."},
	[ 41] = {"EWOULDBLOCK",		"Operation would block (may be same value as EAGAIN) (POSIX.1)."},
	[ 42] = {"ENOMSG",		"No message of desired type (POSIX.1)."},
	[ 43] = {"EIDRM",		"Identifier removed (POSIX.1)."},
	[ 44] = {"ECHRNG",		"Channel number out of range"},
	[ 45] = {"EL2NSYNC",		"Level 2 not synchronized"},
	[ 46] = {"EL3HLT",		"Level 3 halted"},
	[ 47] = {"EL3RST",		"Level 3 reset"},
	[ 48] = {"ELNRNG",		"Link number out of range"},
	[ 49] = {"EUNATCH",		"Protocol driver not attached"},

	[ 50] = {"ENOCSI",		"No CSI structure available"},
	[ 51] = {"EL2HLT",		"Level 2 halted"},
	[ 52] = {"EBADE",		"Invalid exchange"},
	[ 53] = {"EBADR",		"Invalid request descriptor"},
	[ 54] = {"EXFULL",		"Exchange full"},
	[ 55] = {"ENOANO",		"No anode"},
	[ 56] = {"EBADRQC",		"Invalid request code"},
	[ 57] = {"EBADSLT",		"Invalid slot"},
	[ 58] = {"EDEADLOCK",		"Synonym for EDEADLK."},
	[ 59] = {"EBFONT",		"Bad font file format"},

	[ 60] = {"ENOSTR",		"Device not a stream (POSIX.1 (XSI STREAMS option))."},
	[ 61] = {"ENODATA",		"No message is available on the STREAM head read queue (POSIX.1)."},
	[ 62] = {"ETIME",		"Timer expired (POSIX.1 (XSI STREAMS option))."},
	[ 63] = {"ENOSR",		"Out of streams resources (POSIX.1 (XSI STREAMS option))."},
	[ 64] = {"ENONET",		"Machine is not on the network"},
	[ 65] = {"ENOPKG",		"Package not installed"},
	[ 66] = {"EREMOTE",		"Object is remote"},
	[ 67] = {"ENOLINK",		"Link has been severed (POSIX.1)."},
	[ 68] = {"EADV",		"Advertise error"},
	[ 69] = {"ESRMNT",		"Srmount error"},

	[ 70] = {"ECOMM",		"Communication error on send"},
	[ 71] = {"EPROTO",		"Protocol error (POSIX.1)."},
	[ 72] = {"EMULTIHOP",		"Multihop attempted (POSIX.1)."},
	[ 73] = {"EDOTDOT",		"RFS specific error"},
	[ 74] = {"EBADMSG",		"Not a data message (POSIX.1)."},
	[ 75] = {"EOVERFLOW",		"Value too large for defined data type (POSIX.1)."},
	[ 76] = {"ENOTUNIQ",		"Name not unique on network"},
	[ 77] = {"EBADFD",		"File descriptor in bad state"},
	[ 78] = {"EREMCHG",		"Remote address changed"},
	[ 79] = {"ELIBACC",		"Can not access a needed shared library"},

	[ 80] = {"ELIBBAD",		"Accessing a corrupted shared library"},
	[ 81] = {"ELIBSCN",		".lib section in a.out corrupted"},
	[ 82] = {"ELIBMAX",		"Attempting to link in too many shared libraries"},
	[ 83] = {"ELIBEXEC",		"Cannot exec a shared library directly"},
	[ 84] = {"EILSEQ",		"Illegal byte sequence (POSIX.1, C99)."},
	[ 85] = {"ERESTART",		"Interrupted system call should be restarted"},
	[ 86] = {"ESTRPIPE",		"Streams pipe error"},
	[ 87] = {"EUSERS",		"Too many users"},
	[ 88] = {"ENOTSOCK",		"Socket operation on non-socket (POSIX.1)."},
	[ 89] = {"EDESTADDRREQ",	"Destination address required (POSIX.1)."},

	[ 90] = {"EMSGSIZE",		"Message too long (POSIX.1)."},
	[ 91] = {"EPROTOTYPE",		"Protocol wrong type for socket (POSIX.1)."},
	[ 92] = {"ENOPROTOOPT",		"Protocol not available (POSIX.1)."},
	[ 93] = {"EPROTONOSUPPORT",	"Protocol not supported (POSIX.1)."},
	[ 94] = {"ESOCKTNOSUPPORT",	"Socket type not supported"},
	[ 95] = {"EOPNOTSUPP",		"Operation not supported on transport endpoint (POSIX.1)."},
	[ 96] = {"EPFNOSUPPORT",	"Protocol family not supported"},
	[ 97] = {"EAFNOSUPPORT",	"Address family not supported by protocol (POSIX.1)."},
	[ 98] = {"EADDRINUSE",		"Address already in use (POSIX.1)."},
	[ 99] = {"EADDRNOTAVAIL",	"Cannot assign requested address (POSIX.1)."},

	[100] = {"ENETDOWN",		"Network is down (POSIX.1)."},
	[101] = {"ENETUNREACH",		"Network is unreachable (POSIX.1)."},
	[102] = {"ENETRESET",		"Network dropped connection because of reset (POSIX.1)."},
	[103] = {"ECONNABORTED",	"Software caused connection abort (POSIX.1)."},
	[104] = {"ECONNRESET",		"Connection reset by peer (POSIX.1)."},
	[105] = {"ENOBUFS",		"No buffer space available (POSIX.1 (XSI STREAMS option))."},
	[106] = {"EISCONN",		"Transport endpoint is already connected (POSIX.1)."},
	[107] = {"ENOTCONN",		"Transport endpoint is not connected (POSIX.1)."},
	[108] = {"ESHUTDOWN",		"Cannot send after transport endpoint shutdown"},
	[109] = {"ETOOMANYREFS",	"Too many references: cannot splice"},

	[110] = {"ETIMEDOUT",		"Connection timed out (POSIX.1)."},
	[111] = {"ECONNREFUSED",	"Connection refused (POSIX.1)."},
	[112] = {"EHOSTDOWN",		"Host is down"},
	[113] = {"EHOSTUNREACH",	"No route to host (POSIX.1)."},
	[114] = {"EALREADY",		"Operation already in progress (POSIX.1)."},
	[115] = {"EINPROGRESS",		"Operation now in progress (POSIX.1)."},
	[116] = {"ESTALE",		"Stale file handle (POSIX.1)."},
	[117] = {"EUCLEAN",		"Structure needs cleaning"},
	[118] = {"ENOTNAM",		"Not a XENIX named type file"},
	[119] = {"ENAVAIL",		"No XENIX semaphores available"},

	[120] = {"EISNAM",		"Is a named type file"},
	[121] = {"EREMOTEIO",		"Remote I/O error"},
	[122] = {"EDQUOT",		"Disk quota exceeded (POSIX.1)."},
	[123] = {"ENOMEDIUM",		"No medium found"},
	[124] = {"EMEDIUMTYPE",		"Wrong medium type"},
	[125] = {"ECANCELED",		"Operation Canceled (POSIX.1)."},
	[126] = {"ENOKEY",		"Required key not available"},
	[127] = {"EKEYEXPIRED",		"Key has expired"},
	[128] = {"EKEYREVOKED",		"Key has been revoked"},
	[129] = {"EKEYREJECTED",	"Key was rejected by service"},

	[130] = {"EOWNERDEAD",		"Owner died"},
	[131] = {"ENOTRECOVERABLE",	"State not recoverable"},
	[132] = {"ERFKILL",		"Operation not possible due to RF-kill"},
	[133] = {"EHWPOISON",		"Memory page has hardware error"}
};


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
