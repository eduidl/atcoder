# http://abc064.contest.atcoder.jp/tasks/abc064_b

# submitted code

# N = gets.to_i
# a = gets.split(" ").map(&:to_i)
#
# puts a.max - a.min

# refactored code
gets
a = gets.split.map(&:to_i)
puts a.max - a.min
