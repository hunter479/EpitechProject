--
-- EPITECH PROJECT, 2019
-- FUN_hal_2019
-- File description:
-- Expr
--

module Expr
(
    evalSequence
)  where

import Data
import Handler
import Function

eval :: Env -> Expression -> (Env, Expression)
eval environment (Null) = (environment, Null)
eval environment (Boolean bool) = (environment, Boolean bool)
eval environment (Number number) = (environment, Number number)
eval environment (Array array) = (environment, Array array)
eval environment (Variable variable) = (environment, findValue environment variable)
eval environment (Definition variable expression) = ((addBinding newEnvironment symbol value), value)
    where (newEnvironment, value) = eval environment expression
          (Variable symbol) = variable
eval environment var@(Application operator operands) =
    let (firstEnvironment, op) = eval environment operator
        (finalEnvironment, arguments) = evalList firstEnvironment operands
        (Just exception) = firstException arguments
        in case op of
            Prim "+" -> (finalEnvironment, (addNumbers arguments))
            Prim "-" -> (finalEnvironment, (subNumbers arguments))
            Prim "*" -> (finalEnvironment, (mulNumbers arguments))
            Prim "<" -> (finalEnvironment, (nbLessThan arguments))
            Prim "div" -> (finalEnvironment, (modNumbers arguments))
            Prim "mod" -> (finalEnvironment, (modNumbers arguments))
            Prim "cons" -> (finalEnvironment, (createPair arguments))
            Prim "car" -> (finalEnvironment, (pairFirst arguments))
            Prim "cdr" -> (finalEnvironment, (pairSecond arguments))
            Prim "list" -> (finalEnvironment, (createList arguments))
            Prim "eq?" -> (finalEnvironment, (eqExpr arguments))
            _ -> (finalEnvironment, Exception "Can't apply something which is not a procedure.")

eval environment _ = (environment, Exception "Can't evaluate - not supported")

evalList :: Env -> [Expression] -> (Env, [Expression])
evalList environment [] = (environment, [])
evalList environment (e:es) =
    let (firstEnvironment, resultFirst) = eval environment e
        (finalEnvironment, resultFinal) = evalList firstEnvironment es
    in (finalEnvironment, resultFirst : resultFinal)

firstException :: [Expression] -> Maybe Expression
firstException [] = Nothing
firstException (e:es) = case e of
                            (Exception string) -> Just e
                            _ -> firstException es


evalSequence :: Env -> [Expression] -> (Env, Expression)
evalSequence environment [] = (environment, Null)
evalSequence environment (e:[]) = eval environment e
evalSequence environment (e:es) = evalSequence env1 es
    where (env1, result) = eval environment e
