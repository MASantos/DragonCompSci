

-- true :: (a -> b -> c) -> (a -> b -> c) -> (a -> b -> c)
-- false :: (a -> b -> c) -> (a -> b -> c) -> (a -> b -> c)

-- true :: x -> y -> x
-- false :: x -> y -> y
-- true x y = x
-- false x y = y
-- 
-- -- not :: ((a -> b -> c) -> (a -> b -> c) -> (a -> b -> c)) -> ((a -> b -> c) -> (a -> b -> c) -> (a -> b -> c))
-- 
-- not :: x -> y -> z -> 
 
true = \x y -> x
false = \x y -> y
lnot = \b -> b false true

bol = lnot true

main = do 
    print $ false 1 2 == ( lnot true ) 1 2
    print $ true 1 2 == ( lnot false ) 1 2
    print $ true 777 2 == ( lnot false ) 777 2


