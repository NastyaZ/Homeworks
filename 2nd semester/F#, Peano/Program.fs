//Зотова А., 171 гр
type Peano=Zero | S of Peano

let suc (p : Peano) = S p

let rec plus a b =
  match a with
  | Zero->b
  |S a -> S (plus a b)

let rec minus a b =
  match b with
  |Zero -> a
  |S b-> 
    match a with
    |Zero->Zero
    |S a -> minus a b

let rec mul a b =
  match b with
  |Zero->Zero
  |S b -> plus a (mul a b)

let rec pr a =
  match a with
  |Zero->0
  |S a -> (pr a)+1

let str a =
  a.ToString()

let print a = a |> pr
                |> str
                |> printf "%s\n"
let rec step x y =
  match y with 
  |Zero->(S Zero)
  |S y -> mul x (step x y)


[<EntryPoint>]
let main argv=
  let b= S (S (S Zero))
  let a= S (S (S (S (S (S Zero)))))
  printf "a=" 
  print a
  printf "b=" 
  print b
  printf "a+b=" 
  print (plus a b)
  printf "a-b=" 
  print (minus a b)
  printf "a*b=" 
  print (mul a b)
  printf "a^b=" 
  print (step a b) 
  0