def answer(n)
  keta = n.to_s.size - 1
  return n if keta == 0
  left = n.to_s[0].to_i
  (n == (left + 1) * 10**keta - 1) ? keta * 9 + left : keta * 9 + left - 1
end
 
puts answer(gets.to_i)
