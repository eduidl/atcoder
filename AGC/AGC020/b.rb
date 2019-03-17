def answer(arr)
  min, max = 2, 2
  arr.reverse_each do |a|
    return -1 if max % a != 0 && max / a * a < min
    new_min = (min % a == 0) ? min : (min / a + 1) * a
    min, max = if new_min + a > max
                 [new_min, new_min + a - 1]
               else
                 [new_min, max / a * a + a - 1]
               end
  end
  return "#{min} #{max}"
end

_ = gets
a = gets.split.map(&:to_i)
puts answer(a)
