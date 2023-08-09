#! bin/bash
echo "Employee Record....."
createRecord () {
	name=""
        empId=""
        telNum=""
        read -p "Enter name of Employee - " name
	read -p "Enter employee ID - " empId
	read -p "Enter telephone number of Employee - " telNum
	if grep -q "Employee Number : ${empNumber}" "record.txt"; then
		echo "Employee ID already exists"
	else
		echo "Name : $name    Employee ID : $empId   Telephone Number : $telNum" >> record.txt
		echo "Added Successfully"
	fi
}
deleteRecord() {
	empId=""
	read -p "Enter Employee ID to be deleted - " empId
        if grep -q "Employee ID : ${empId}" "record.txt"; then
		sed -i "/Employee ID : ${empId}/d" record.txt
		echo "Deleted Successfully"
	else
		echo "Employee ID invalid"
	fi
}
search() {
	identity=""
	read -p "Enter employee name / employee id to search - " identity
	grep "Name : ${identity}" "record.txt"
	grep "Employee ID : ${identity}" "record.txt"
}
list() {
	echo ""
	cat record.txt
	echo ""
}
sortRecords() {
	sort -t ':' -k 3 -n record.txt > temp.txt
	mv temp.txt record.txt

}
while [ 1 -lt 10 ]
do
	echo "Operations :-"
	echo "1) Create employee record"
	echo "2) Delete employee record"
	echo "3) Search employee record"
	echo "4) List employee record"
	echo "5) Sort employee record"
	echo "6) Exit"
	op=0
	read -p "Enter operation number(1-6) - " op
	case $op in
		1) createRecord;;
		2) deleteRecord;;
		3) search;;
		4) list;;
		5) sortRecords;;
		6) break;;
		*) echo "Invalid number";;
	esac
done

