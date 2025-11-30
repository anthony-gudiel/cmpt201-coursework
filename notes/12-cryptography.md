# Cryptography Algorithms

## The Absolute Basics
- The CIA model:
    - **Confidentiality**: information is only disclosed to those authorized to know it
    - **Integrity**: only modify information in allowable ways, and only by authorized parties
    - **Availability**: those authorized for access are not prevented from it
- General cryptography process: plain text -> cipher text -> plain text
    - encrypt -> decrypt
- **Caesar Cipher**: shift each letter a certain number of letters down the alphabet
    - +1: A becomes B
- The problem with a secret algorithm is that once the algorithm is known, the code is useless
- In modern encryption, the algorithms are public, but the keys are secret
    - If only the key is private, it's easy to replace with a new key if it's figured out
    - Given a key, it should be relatively easy to encrypt or decrypt the message
    - Without they key, it should be hard to compute or decrypt a message
- The **Window of Validity** is the minimum time to compromise a cryptographic algorithm
    - Must only use algorithms that have not been compromised
    - The problem is that the window of validity may be shorter than how long you need the algorithm
      to be effective for
        - Therefore we need a way to replace encryption function easily
- Zero key encryption: **cryptographic hash functions**
- One key encryption: **secret-key functions** (symmetric encryption)
- Two key encryption: **public-key functions** (asymmetric encryption)

## Zero Key Encryption
- Hash function *h()* takes a message *m* as input and produces a smaller (shorter) number *h(m)*
- Hash functions need to be:
    - Easy to compute
    - A one way function, the reverse should be difficult to compute
    - Given an input, it should be difficult to find another input value that produces the same hash value (weak
      collision resistance)
    - Given a hash function, it should be difficult to find any two values that produce the same
      hash (strong collision resistance)
        - Any two inputs, whereas weak collision resistance is for a particular input

## Private Key Encryption (One Key or Symmetric)
- A single key is used for both encryption and decryption
- Requires a secure way to share the key
- AES is an example of a private key encryption

## Public Key Encryption (Two Key or Asymmetric)
- Encrypt plain text using a public key
- Decrypt cipher text using the private key
- Can also go the other way:
    - Plain text to cipher text using private key
    - Cipher text to plain text using public key
    - Different cipher text depending on direction
- The private key should be known only to the owner of the key
- When encrypted with one key, only the other key can decrypt it
- Applying the same algorithm using each key gets you back the original message
    - Always using the same algorithm, keys are inverse of each other
- The public and private keys are generated together as part of a solution to some very hard to
  reverse computation
- To verify sender, the owner of the private key encrypts the plain text with his private key
    - The owner is the only one who can encrypt a message that can be decrypted using the public key
- One of the strengths about this method is that it doesn't require having a secure key distribution
  mechanism

## Storing Passwords
- Passwords are hashed, and only the hash is stored
- To check a password, the system checks: hash(user-input) == stored hash
- In a rainbow table attack, the attacker pre-computes the hash of common passwords
    - To defend against this, every password is salted
        - The salt is a random number or string that is added before the hash of the actual password
        - Each user has unique salt. Therefore the attacker cannot compute hash of all possible
          passwords alongside all possible salts

## Verifying Documents
- A **secure digest** is a fixed length string that characterizes an arbitrary-length message
- We want to verify that a message or document is an unaltered copy of the one produced by the
  signer
    - Combination of public key cryptography and hashing
- The signer wants to prove they sent the message
    - To do so, they encrypt the digest using their own private key (called signing)
    - Send both the message and the signature
- The verifier will:
    - Decrypt the signature with the signer's public key
    - Verify that *h(m) == h'*. If true -> authentic
- Since only the signer knows their private key, if the signature can be decrypted with the public
  key, then it must be from the signer
