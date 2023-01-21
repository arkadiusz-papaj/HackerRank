/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

[[nodiscard]] auto timeConversion(string s) -> string {
    //hh:mm:ssAM
    auto hour = stoi(s.substr(0, 2));

    if ((s.find("AM") != string::npos) and (hour == 12)){
        s.replace(0, 2, "00");
    }
    if ((s.find("PM") != string::npos) and (hour < 12)) {
        s.replace(0, 2, std::to_string(hour + 12));
    }

    return s.substr(0, 8);
}