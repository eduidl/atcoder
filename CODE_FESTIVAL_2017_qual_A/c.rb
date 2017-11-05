# http://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_c

# submitted code

# h, w = gets.split(' ').map(&:to_i)
# letter_count = {}
# four_count = 0
# h.times do
#   a = gets.chomp.split(//)
#   a.each do |aa|
#     if letter_count.key?(aa)
#       if letter_count[aa] == 3
#         four_count += 1
#         letter_count[aa] = 0
#       else
#         letter_count[aa] += 1
#       end
#     else
#       letter_count[aa] = 1
#     end
#   end
# end
#
# h, w = w, h if h % 2 == 1
#
# if h % 2 == 0 && w % 2 == 0
#   if four_count * 4 == h * w
#     puts 'Yes'
#   else
#     puts 'No'
#   end
# elsif h % 2 == 0 && w % 2 == 1
#   if four_count * 4 >= h * (w - 1) && letter_count.values.all? { |v| v % 2 == 0 }
#     puts 'Yes'
#   else
#     puts 'No'
#   end
# else
#   if four_count * 4 >= (h - 1) * (w - 1) && letter_count.values.count { |v| v % 2 == 1} == 1
#     puts 'Yes'
#   else
#     puts 'No'
#   end
# end

# refactored code

def exits?(h, w)
  letter_count = {}
  h.times do
    gets.chomp.split(//).each do |aa|
      letter_count[aa] ||= 0
      letter_count[aa] = (letter_count[aa] + 1) % 4
    end
  end
  letter_count.reject! { |_k, v| v.zero? }

  h, w = w, h if h.odd?

  if h.even? && w.even?
    letter_count.values.empty?
  elsif h.even? && w.odd?
    letter_count.values.all?(&:even?) && letter_count.values.inject(:+) <= h
  else
    letter_count.values.count(&:odd?) == 1 && letter_count.values.inject(:+) <= h + w - 1
  end
end

puts exits?(*gets.split.map(&:to_i)) ? 'Yes' : 'No'
