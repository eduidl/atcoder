# http://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_c

# submitted code

# n, m, k = gets.split(' ').map(&:to_i)
# flg = false
# 0.upto(n) do |nn|
#   0.upto(m) do |mm|
#     if nn * (m - mm) + (n - nn) * mm == k
#       puts 'Yes'
#       flg = true
#       break
#     end
#   end
#   break if flg
# end
# puts 'No' unless flg

# refactored code

n, m, k = gets.split.map(&:to_i)
puts (0..n).to_a.product((0..m).to_a).any? { |nn, mm| nn * (m - mm) + (n - nn) * mm == k } ? 'Yes' : 'No'
