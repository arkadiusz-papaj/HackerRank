/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a std::string.
 * The function accepts std::string s as parameter.
 */

[[nodiscard]] auto timeConversion(std::string s) -> std::string {
    //hh:mm:ssAM
    auto hour = stoi(s.substr(0, 2));

    if ((s.find("AM") != std::string::npos) and (hour == 12)){
        s.replace(0, 2, "00");
    }
    if ((s.find("PM") != std::string::npos) and (hour < 12)) {
        s.replace(0, 2, std::to_string(hour + 12));
    }

    return s.substr(0, 8);
}