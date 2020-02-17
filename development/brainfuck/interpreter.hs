import System.Environment
import Data.List

data Token = Token Int Int Char

parseArgs :: [String] -> (String, String)
parseArgs [] = error "Usage : runghc interpreter.hs <source_file> <input_file>"
parseArgs (x:[]) = (x, "")
parseArgs (x:y:[]) = (x, y)

getFileData :: String -> IO String
getFileData "" = return ""
getFileData x = readFile x

parseSourceCode :: String -> [Token]
parseSourceCode str 
    | 

main = do
    args <- getArgs
    let (source_file, input_file) = parseArgs args
    source_code <- getFileData source_file
    input_data <- getFileData input_file

     