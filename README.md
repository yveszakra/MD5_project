# MD5_project
The main objective of our project is to demonstrate our understanding of password-based authentication. Our program is written in C++. We are implementing a scheme that can be found on all UNIX variants as well as on a number of other operating systems. It is a widely used password security technique that uses hashed passwords and a salt value. The program consists of creating a password file containing the user IDs, the salt values, and hash codes. Once the file is created and populated, the program proceeds to authenticate the password. It then ends by running the rainbow table implementation in order to crack the password.

I. INTRODUCTION
Our UNIX password implementation is based on the “Message Digest 5 algorithm”, or better known as the MD5 algorithm. MD5 is a cryptographic hash function that takes in an input of some length and produces a message hash that is 128 bits long. 

The algorithm works in 5 steps. The first step is to add padding bits. The original message, or in this case passwords, are padded so that its length in bits is congruent to 448 modulo 512. This means that the message is extended so that it is about 64 bits of being a multiple of 512 bits long. The padding is done by appending a single ‘1’ bit to the message, then ‘0’ bits are appended until the requirements of the padding are met.

The next step is appending 64 bits onto the now modified message. These bits represent the length of the original message before padding was added. In the event that the length of a message is greater than 2^64, only the low-order 64 bits will be used. 



Once the previous steps are finished, the message digest buffer will initialize. A four word buffer, usually labeled as A,B,C,and D, is used to compute the message digest. These are 32 bits each and initialized like the following:
 state[0] = 0x67452301;
 state[1] = 0xefcdab89;
 state[2] = 0x98badcfe;
 state[3] = 0x10325476;
The next step is to process the message in 512-bit blocks. For each input block, 4 rounds of operations are performed with 16 operations each round. Figure 1 shows an illustration of the process.
 
Figure 1. Illustration of how the blocks are processed.

The final step is the output of the message digest. It is outputted in the following order: 
A, B, C, D. With A being the lowest order byte and D being the highest order byte. 

All these steps together make the MD5 algorithm and the basis for the project. 


II. IMPLEMENTATION DETAILS

The structure of the program is split into four major parts: MD5 Algorithm, Password authentication, Rainbow Attack Table, and Main/Driver. Each section was created by different individuals and combined together to create an implementation of the MD5 algorithm and rainbow table attack.

MD5 Algorithm:
 The MD5 algorithm was developed with the main motive of security as it takes an input of any size and produces an output of a 128-bit hash value. To be considered cryptographically secure, MD5 should meet two requirements:
1.	It is impossible to generate two inputs that cannot produce the same hash function.
2.	It is impossible to generate a message having the same hash value.

Initially, MD5 was developed to store one way hash of a password, and some file servers also provide pre-computed MD5 checksum of a file so that the user can compare the checksum of the downloaded file to it. Most Unix-based Operating Systems include MD5 checksum utilities in their distribution packages.
There are 4 main steps in our MD5 algorithm implementation. The first one is to append the padding bits. Padding means adding extra bits to the original message. So in MD5 the original message is padded such that its length in bits is congruent to 448 modulo 512. Padding is done such that the total bits are 64 less, being a multiple of 512 bits length. It is done even if the length of the original message is already congruent to 448 modulo 512. In padding bits, the only first bit is 1, and the rest of the bits are 0.
The second step is to append the length. After padding, 64 bits are inserted at the end, which is used to record the original input length. Modulo 2^64. At this point, the resulting message has a length multiple of 512 bits.
The third step is the Message Digest buffer initialization. A four-word buffer (A, B, C, D) is used to compute the values for the message digest. Here A, B, C, D are 32- bit registers.
And finally, the fourth step, which consists of processing the message in a 16-word block. MD5 uses the auxiliary functions, which take the input as three 32-bit numbers and produce 32-bit output. These functions use logical operators like OR, XOR, NOR. The content of four buffers are mixed with the input using this auxiliary buffer, and 16 rounds are performed using 16 basic operations.

Password Authentication:
The password authentication process borrows ideas from the MD5 algorithm. This process looks up the user id, grabs the supposed password, runs it through the MD5 algorithm with the accompanying salt value and compares if the saved hash value in the file system is the same as the newly generated hash value. 

Our implementation follows these steps very closely. When given a user ID and password, the system calls the password authentication function. This function opens the text file that holds all the user ids, salt values, and hash values. The system searches for the given user id and obtains the associated salt value and hash value. With the salt value, the system combines it with the given password and runs the MD5 algorithm. Once the newly generated hash is given the system compares the generated hash with the hash associated with the user ID. If the password is not valid, the system will state the password is not correct. If the password is valid, the system will state it is correct.

Rainbow Attack Table:
The rainbow attack table utilized the idea of precomputing hundreds of thousands of words from the English dictionary as well as slang and other common passwords that can be found online from database dumps. These precomputed common words and passwords were initially stored in a dictionary text file, but we used our MD5 hash function to compute every hash value for each word inside of that dictionary text file and we stored the word and the newly computed hash value in separate columns... inside of a new text file called DictionaryTable. 

We then also took a stab at randomly generating around 500,000 - 2,000,000 passwords and storing them inside of their own text file called RT. During program execution when the user wants to crack a password the program will search through the DictionaryTable and RT text files. The program is trying to match the hash value from a specified User_ID that is found inside the userFile text file. Once the hash values are matched the password will be displayed to the console. If a password is not found it will tell the user it was not able to find a password for another user.

MD5 Main/Driver:
In main.cpp we have one function that is called menu. This menu function consists of a while loop that has a switch statement inside of it. There are 4 cases for the switch statement. One for adding a user, two for logging in as a user, three to crack a user’s password just based on their userID, and four to exit the menu and the program. This menu calls functions from the RainbowTable.cpp and md5.cpp to help complete its tasks efficiently.

III. RUNNING RESULTS AND ANALYSIS
In Figure 1 we show that when the password that we are looking for in the RainbowTable file and the Dictionary file is at the beginning it takes less than 2 seconds to find its match. The later in the file the password is located the longer time it takes to run. If the file is not in either of the files the time complexity goes quadratic and can take up to days to brute force.
 
Figure 1: Search time vs password location

In figure 2 we show that the later in the alphabet that the password is the longer time it takes to find its match. This is due to the rainbow table files being alphabetic causing the read time to be longer.

 
Figure 2: Search time vs character position

IV. CONCLUSION
Our group project was divided into multiple. Where Yves worked on creating the MD5 hash function and generating salt values for our user file, Thomas worked on verifying the passwords by matching the User ID and matching the hash values via our user file, Tyler developed the rainbow attack table and main.cpp user interface. Joseph assisted Tyler in developing the rainbow attack table plus he assisted with fixing bug fixes. Overall, during our research, we increased our understanding of the MD5 hash algorithm. We learned ideas such as that we need to salt our passwords before hashing them for better security. Another idea was: if we salt our passwords, we would not be able to crack passwords using the rainbow attack table due to the fact that salted passwords become too long to crack.
