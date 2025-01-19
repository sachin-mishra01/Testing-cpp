import pandas as pd
import matplotlib.pyplot as plt

# Read data from the CSV file
data = pd.read_csv("comparisons.csv")

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(data["Data Size"], data["Best Case"], label="Best Case", marker='o')
plt.plot(data["Data Size"], data["Worst Case"], label="Worst Case", marker='o')
plt.plot(data["Data Size"], data["Average Case"], label="Average Case", marker='o')
plt.plot(data["Data Size"], data["Time Taken"],label="Time Taken",color="red",marker="o")

# Add titles and labels
plt.title("Linear Search Comparisons")
plt.xlabel("Array Size (n)")
plt.ylabel("Number of Comparisons")
plt.legend()
plt.grid(True)

# Save the plot as an image (optional)
plt.savefig("linear_search_plot.png")

# Show the plot
plt.show()
