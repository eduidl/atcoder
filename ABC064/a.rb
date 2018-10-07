# http://abc064.contest.atcoder.jp/tasks/abc064_a

# submitted code

# i = gets.gsub(/ /, "").to_i
# if i % 4 == 0
#   puts "YES"
# else
#   puts "NO"
# end

# refactored code
puts gets.delete(' ').to_i % 4 == 0 ? 'YES' : 'NO'
