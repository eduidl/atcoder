# http://agc017.contest.atcoder.jp/tasks/agc017_a

# submitted code

# N, P = gets.split(" ").map(&:to_i)
# A = gets.split(" ").map(&:to_i)
#
# odd, even = 0, 1
# A.each do |a|
#   if a % 2 == 0
#     odd, even = odd * 2, even * 2
#   else
#     odd, even = odd + even, odd + even
#   end
# end
#
# puts P.zero? ? even : odd

# refactored code

_n, p = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

cases = a.each_with_object({ odd: 0, even: 1 }) do |aa, hash|
  if aa.even?
    hash[:odd] *= 2
    hash[:even] *= 2
  else
    hash[:odd] = hash[:even] = hash[:odd] + hash[:even]
  end
end
puts p.zero? ? cases[:even] : cases[:odd]
