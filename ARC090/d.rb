# 間違っている

def answer(lrd)
  while lrd.size >= 1
    l1, r1, d1 = lrd.pop
    lrd.each_with_index do |(l, r, d), j|
      p [l, r, d]
      if l == l1 && r == r1
        if d1 == d
          lrd[j] = nil
        else
          return 'No'
        end
      elsif l == r1 && r == l1
        p 2
        if d1 == -d
          lrd[j] = nil
        else
          return 'No'
        end
      elsif l1 == l
        lrd[j] = [r1, r, d - d1]
      elsif l1 == r
        lrd[j] = [l, r1, d + d1]
      end
    end
    lrd.compact!
  end
  'Yes'
end

n, m = gets.split.map(&:to_i)

lrd = []
m.times do
  lrd << gets.split.map(&:to_i)
end

puts answer(lrd)
