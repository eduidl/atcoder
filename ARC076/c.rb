# http://arc076.contest.atcoder.jp/tasks/arc076_a

# submitted code

# def kaijou(n)
#   kekka = 1
#   1.upto(n) do |i|
#     kekka = kekka * (i ** 2) % (10**9 + 7)
#   end
#   kekka
# end
#
# N, M = gets.split(" ").map(&:to_i)
# N, M = M, N if N < M
# if N - M > 1
#   puts 0
# elsif N - M == 1
#   puts (kaijou(M) * N) % (10**9 + 7)
# else
#   puts (kaijou(M) * 2) % (10**9 + 7)
# end

# refactored code
MODULO_BY = 10**9 + 7

def squaring_factorial(n)
  (1..n).to_a.inject(1) { |product, i| product * i**2 % MODULO_BY }
end

m, n = gets.split.map(&:to_i).sort
if n - m > 1
  puts 0
elsif n == m
  puts squaring_factorial(m) * 2 % MODULO_BY
else
  puts squaring_factorial(m) * n % MODULO_BY
end