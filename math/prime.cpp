// def primegen():
//   yield 2; yield 3; yield 5; yield 7; yield 11; yield 13
//   ps = primegen() # yay recursion
//   p = ps.next() and ps.next()
//   q, sieve, n = p**2, {}, 13
//   while True:
//       if n not in sieve:
//           if n < q: yield n
//           else:
//               next, step = q + 2*p, 2*p
//               while next in sieve: next += step
//               sieve[next] = step
//               p = ps.next()
//               q = p**2
//       else:
//           step = sieve.pop(n)
//           next = n + step
//           while next in sieve: next += step
//           sieve[next] = step
//       n += 2
        
// def prime_str(n):
//   primes = primegen()
//   res = ""
//   while len(res) < 5:f
//       strp = str(next(primes))
//       L = len(strp)
//       if L >= n:
//           res += strp[n:n+5]
//       n = max(0, n-L)
//   return res[:5]
  
// def solution(i):
//   s = prime_str(i);
//   return s;
    
// a  = solution(3);
// print(a)