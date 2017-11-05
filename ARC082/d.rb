# http://arc082.contest.atcoder.jp/tasks/arc082_a

# submitted code

# n = gets.to_i
# a = gets.split.map(&:to_i)
#
# count = 0
# flag = false
# n.times do |nn|
#   if flag
#     flag = false
#     next
#   elsif a[nn] == nn + 1 && a[nn + 1] == nn + 2
#     flag = true
#     count += 1
#   elsif a[nn] == nn + 1
#     count += 1
#   end
# end
#
# puts count

# refactored code

def answer(n, a)
  count = 0
  n.times do |nn|
    next if a[nn] != nn + 1
    a[nn], a[nn + 1] = a[nn + 1], a[nn]
    count += 1
  end
  count
end

n = gets.to_i
a = gets.split.map(&:to_i)
puts answer(n, a)