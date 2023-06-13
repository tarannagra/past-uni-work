"""
    main.py - Made by Taran Nagra
    ---
    Purpose:
        For 4005CEM - Task 2
"""

import pandas as pd
import matplotlib.pyplot as plt

# print(plt.style.available)
plt.style.use("seaborn-v0_8-deep") # changes the style of the bars and sometimes the background

class Plot:
    """
    # Plot
    ---
    This class represents the different data in the program.
    Anything that would want to be requested can be changed with 
    one line, making it very flexible for future use.
    """
    def __init__(self, dataset:str) -> None:
        self.data = pd.read_csv(dataset)

        # Even if I do not intend to use the all data listed
        # it is here incase a future developer would need it.

        # Below you may see list(set(self...))
        # This piece of code translates the list into a set and then a list
        # This removes the duplicates in the code as it will add unnecessary values

        # I have spaced out the following variables so it has better legibility.

        self.ownerID =                  list(set(self.data['OwnerID']))
        self.ownerName =                list(set(self.data['OwnerName']))
        self.telNo =                    list(set(self.data['TelNo']))
        self.email =                    list(set(self.data['Email']))

        self.dogID =                    self.data['DogID']
        self.dogName =                  self.data['DogName']
        self.breed =                    self.data['Breed']
        self.size =                     self.data['Size']
        self.coat =                     self.data['Coat']
        self.comments =                 self.data['Comments']

        self.groomOption =              self.data['GroomOption']
        self.description =              self.data['Description']
        self.groomTime =                self.data['GroomTime']
        self.sizeTimeAdjustment =       self.data['SizeTimeAdjustment']
        self.adjustedGroomTime =        self.data['AdjustedGroomTime']
        self.groomCost =                self.data['GroomCost']
        self.sizeCostAdjustment =       self.data['SizeCostAdjustment']
        self.adjustedGroomCost =        self.data['AdjustedGroomCost']
        self.bookingDate =              self.data['BookingDate']
        self.bookingTime =              self.data['BookingTime']
        self.totalLengthOfAppointment = self.data['TOTALLengthofAppointment']
        self.totalCost =                self.data['TOTALCost']
    
    def bar(self) -> None:
        """
        ## Bar chart
        ---
        This bar chart is best suited to show the number of dogs
        there are per breed. This is the best data to show as it
        gives a wide insight towards the dogs we have and their breed.
        """
        breed_counts = self.breed.value_counts()
        breed_counts.plot(kind="bar")
        plt.title(
            label="Number of Dogs per Breed",
            loc="center"
        )
        plt.xlabel("Breeds")
        plt.ylabel("Count")
        plt.show()

    def pie(self) -> None:
        """
        ## Pie chart
        ---
        This pie chart is best suited to show the most popular
        groom options available for purchase. This data is the best
        to show as it returns the most popular groom options.
        """
        groom_options = self.groomOption.value_counts()
        plt.pie(
            groom_options,
            labels=groom_options.index,
            autopct="%1.1f%%"
        )
        plt.title(
            label="Most popular groom options",
            loc="center"
        )
        plt.show()

    def scatter(self) -> None:
        """
        # Scatter
        ---
        This scatter graph is best suited to show the total cost
        vs the dog IDS. This data is the best to show as it gives a brief
        overview of how much each dog is costing on average after costs.
        """
        plt.scatter(
            self.totalCost,
            self.dogID,
        )
        plt.xlabel(xlabel="Total Cost")
        plt.ylabel(ylabel="Dog ID")
        plt.title(
            label="Total cost vs Dog ID",
            loc="center"
        )
        plt.show()

    def stem(self) -> None:
        """
        # Stem
        ---
        This stem graph is best suited to compare the groom cost, adjusted groom cost,
        and the total cost in the establishment. For readability, I have added a legend
        which shows what each line represents. It will help for those who will not know.
        """
        plt.stem(
            self.groomCost,
            linefmt="blue",
            markerfmt="bo",
            label="Groom Cost"
        )
        plt.stem(
            self.adjustedGroomCost,
            linefmt="red",
            markerfmt="ro",
            label="Adjusted Groom Cost"
        )
        plt.stem(
            self.totalCost,
            linefmt="green",
            markerfmt="go",
            label="Total Cost"
        )
        plt.xlabel(xlabel="Index")
        plt.ylabel(ylabel="Cost")
        plt.legend()
        plt.show()

# This makes sure that the file is ran by main.py and not as an external library

if __name__ == '__main__':
    # Initialising the class and passing the parameter: dataset
    plot = Plot(
        "dataset.csv" # this is the dataset we are parsing. Make sure it has the same headings or there will be an error.
    )
    # Closing one of the charts will just open the next one in sequence order as shown below.
    plot.bar()
    plot.pie()
    plot.scatter()
    plot.stem()