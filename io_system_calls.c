/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_system_calls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:18:25 by igama             #+#    #+#             */
/*   Updated: 2023/12/02 18:00:50 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
I/O SYSTEM CALLS

- CREATE: Creates a new empty file. You can specify the permissons for that file.

Libs:
unistd.h for function
fcntl.h for flags

Prototype:
int	create(char *filename, mode_t mode)

filename == Name of the file which you want to create.
mode == indicates permissions of the new file.

Return Value:
Returns the first unused File Descriptor (Generally 3, as 0, 1 and 2 are reserved).
Returns (-1) when an error occurs.





- OPEN: Opens the file you want for reading, writing, or both. It is also capable of creating the file if it does not exist.

Libs:
unistd.h for function
fcntl.h for flags

Prototype:
int	open(const char *path, int flags)

path == Path to the file which you want to open.
Absolute path: Begin with "/" if you're not working in the same directory as the file you're reading.
Relative path: Use directly the file name with it's extension, if you're working in the same directory as the file you're reading.

Flags: Used to specify how you want to open the file.
O_RDONLY	Opens the file in read-only mode.
O_WRONLY	Opens the file in write-only mode.
O_RDWR	Opens the file in read and write mode.
O_CREAT	Create a file if it doesn’t exist.
O_EXCL	Prevent creation if it already exists.
O_ APPEND	Opens the file and places the cursor at the end of the contents.
O_ASYNC	Enable input and output control by signal.
O_CLOEXEC	Enable close-on-exec mode on the open file.
O_NONBLOCK	Disables blocking of the file opened.
O_TMPFILE	Create an unnamed temporary file at the specified path





- CLOSE: Tells the operating system that you are done with a file descriptor and closes the file pointed by the file descriptor.

Libs:
unistd.h for function

Prototype:
int	close(int fd)

fd == File descriptor of the file that you want to close

Return Value:
0 on Sucess.
-1 on Error.





- READ: Reads the specified amount of bytes (cnt) of input into the memory area indicated by (buf). A successful read() updates the access time for the file.

Libs:
unistd.h for function

Prototype:
size_t	read(int fd, void *buf< size_t cnt)

fd == File descriptor of the file from which data is to be read
buf == buffer to read data from
cnt == length of the buffer

Return Value:
Number of bytes read on success
Return 0 if it has reached the end of the file
Return -1 on error or signal interrupt

IMPORTANT POINTS ON READ:
buf needs to point to a valid memory location with a length not smaller than the specified size because of overflow.
fd should be a valid file descriptor returned from open() to perform the read operation because if fd is NULL then the read should generate an error.
cnt is the requested number of bytes read, while the return value is the actual number of bytes read. Also, some times read system call should read fewer bytes than cnt.





- WRITE: Writes (cnt) bytes from (buf) to the file or socket associeated with fd. (cnt) should NOT be greather than INT_MAX (defined in the limits.h header file). If (cnt) is zero, write() simply returns 0 without attempting any other action.

Libs:
unistd for function

Prototype:
size_t write(int fd, void *buf, size_t cnt)

fd == File descriptor
buf == Buffer to write data to
cnt == Length of the buffer

Return Value:
Returns the number of bytes written on success
Return 0 if it has reached the end of the file
Return -1 on error or signal interrupts

IMPORTANT POINTS ON WRITE:
The file needs to be opened for write operations
buf needs to be at least as long as specified by cnt because if buf size is less than the cnt then buf will lead to the overflow condition.
cnt is the requested number of bytes to write, while the return value is the actual number of bytes written. This happens when fd has a less number of bytes to write than cnt.
If write() is interrupted by a signal, the effect is one of the following:
If write() has not written any data yet, it returns -1 and sets errno to EINTR.
If write() has successfully written some data, it returns the number of bytes it wrote before it was interrupted.
If it has already data written inside the file, then the Write System Call overwrite the content and all previous content is *deleted* and the file will only contain the content now written.

*/
