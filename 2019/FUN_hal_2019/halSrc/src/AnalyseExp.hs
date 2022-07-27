--
-- EPITECH PROJECT, 2019
-- FUN_hal_2019
-- File description:
-- AnalyseExp
--

module AnalyseExp
(
    analyzeExpressionSequence
) where

import Data
import Handler

analyzeExpressionSequence :: [Expression] -> [Expression]
analyzeExpressionSequence = map analyzeExpression

analyzeExpression :: Expression -> Expression
analyzeExpression Null = Null
analyzeExpression val@(Pair (Variable "define") _) = buildDefinitionExpression val
analyzeExpression val@(Pair (Array x) _) = Array x
analyzeExpression (Number number) = (Number number)
analyzeExpression (Boolean bool) = (Boolean bool)
analyzeExpression (Variable variable) = (Variable variable)
analyzeExpression val = buildApplicationExpression val

buildDefinitionExpression :: Expression -> Expression
buildDefinitionExpression (Pair _ (Pair variable (Pair value Null))) = Definition variable (analyzeExpression value)

buildApplicationExpression :: Expression -> Expression
buildApplicationExpression (Pair operator operands) = Application (analyzeExpression operator) (map analyzeExpression (pairToList operands))